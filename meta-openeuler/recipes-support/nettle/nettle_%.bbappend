# main bbfile: yocto-poky/meta/recipes-support/nettle/nettle_3.7.2.bb

# version in openEuler
PV = "3.8.1"

# files, patches can't be applied in openeuler or conflict with openeuler
SRC_URI_remove = " \
        ${GNU_MIRROR}/${BPN}/${BP}.tar.gz \
"

# files, patches that come from openeuler
# don't apply 0000-nettle-3.3-remove-ecc-testsuite.patch due to failure: "No known curve with name secp192r1"
SRC_URI += " \
        file://${BP}.tar.gz;name=tarball \
"

SRC_URI[tarball.md5sum] = "e15c5fd5cc901f5dde6a271d7f2320d1"
SRC_URI[tarball.sha256sum] = "364f3e2b77cd7dcde83fd7c45219c834e54b0c75e428b6f894a23d12dd41cbfe"
