import code
from PIL import Image, ImageFilter

#does what filter did in 4 lines of code
before = Image.open("brudge.bmp")
after = before.filter(ImageFilter.BoxBlue(1))
after.save("out.bmp")

# run in terminal by "python blur.py", auto compiles, the compiler is a separate software called python
