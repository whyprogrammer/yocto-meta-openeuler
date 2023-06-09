# add recipes-kernel path to find patch and defconfig
FILESEXTRAPATHS_append := "${THISDIR}/files/:"
# add patch prebuild tools and logo
SRC_URI_append = " \
    file://config/ \
    file://patches/0000-rk3568-kernel.patch.gz;name=rk3568-kernel-patch \
    file://tools \
    file://logo \
"

# patches for ryd-3568
SRC_URI_append_ryd-3568 = " \
    file://patches/0001-rk3568-8897-dts.patch \
    file://patches/0002-ryd-gpio-control.patch \
    "
# mcs patch for ok3568 devicetree
SRC_URI_append = " \
    file://patches/${@bb.utils.contains('MCS_FEATURES', 'ok3568', '0003-ok3568-support-mcs.patch', '', d)} \
"

# more support of device is comming. so we documented this patch md5sum.
SRC_URI[rk3568-kernel-patch.md5sum] = "b4c156e59411c8e86098e03de67a84ca"

# add patch tool to solve patch apply
PATCHTOOL = "git"

OPENEULER_KERNEL_CONFIG = "../config/${MACHINE}/defconfig-kernel"

# add method to do_compile task to produce bootable Image
do_compile_append_rk3568(){
    cp ../logo/* ./
    scripts/mkkrnlimg ${KERNEL_OUTPUT_DIR}/Image kernel.img
    ../tools/mkimg --dtb ${RK3568_KERNEL_DTB_NAME}
    sed -e "s:path_to_kernel:${WORKDIR}\/build:g" -e "s:dtb_name:${RK3568_KERNEL_DTB_NAME}:g" \
        ${WORKDIR}/tools/its_config > .tmp_its_config
    ../tools/mkimage -f .tmp_its_config -E -p 0x800 boot.img
    rm -rf .tmp_its_config
}

# add boot.img to $D
do_install_append(){
    cp ${B}/boot.img ${D}/boot
}
PACKAGES += "bootfile"
FILES_bootfile="/boot/boot.img"
