TEMPLATE = subdirs

SUBDIRS += \
    cli \
    gui \
    tests \
    utils

cli.depends = utils
tests.depends = utils
gui.depends = utils
