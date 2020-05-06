# Plasma Tweaks

Tweaks for Picroma Plasma.

Adds patches for the following:

1) Add the "Widget" icon back to the toolbar. It seems it was commented out for the sneak peek release of Plasma.

2) Add a patch to prevent Nvidia libraries from crashing when despawning a right-click menu while vertex nodes are visible.

3) Add `#version 120` to OpenGL shaders. This fixes Plasma's lack of graphics on Linux, making it usable under Wine. Bring your own Windows fonts, of course.
