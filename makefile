# ----------------------------
# Makefile Options
# ----------------------------

NAME = AERO
ICON = icon.png
DESCRIPTION = "wind tunnel simulation"
COMPRESSED = NO

CFLAGS = -Wall -Wextra -Oz
CXXFLAGS = -Wall -Wextra -Oz

# ----------------------------

include $(shell cedev-config --makefile)
