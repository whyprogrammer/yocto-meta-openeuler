SUMMARY = "linux kernel modules"
PR = "r1"

PACKAGE_ARCH = "${MACHINE_ARCH}"

inherit packagegroup

PACKAGES = "${PN}"

RDEPENDS_${PN} += " \
modutils-initscripts \
"

# please do not add any MACHINE related modules here
# You can use INSTALLMODULES which is defined in machine conf layer
# like: meta-openeuler/conf/machine/kernel-modules-conf/common.inc 
INSTALLMODULES ?= ""
RDEPENDS_${PN} += "${INSTALLMODULES}"
