OPENEULER_SRC_URI_REMOVE = "https git http"

PV = "1.1.1"

SRC_URI_prepend = "file://${BP}.tar.xz \
           file://Fix-pp_sharp_mod-calculation.patch \
           file://examples-fix-underlinking.patch \
           file://examples-png_sizeof-no-longer-available-since-libpng.patch \
"

SRC_URI[sha256sum] = "f36da409947aa2b3dcc6af0a8c2e3144bc19db2ed547d64e9171c59c66561c61"
