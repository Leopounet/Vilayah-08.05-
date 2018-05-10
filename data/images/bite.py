from PIL import Image
import sys

def copy(image, append_image, starting_pos):
    width = append_image.width
    height = append_image.height
    for x in range(width):
        for y in range(height):
            pix = append_image.getpixel((x, y))
            image.putpixel((starting_pos[0] + x, starting_pos[1] + y), pix)

def get_pos(counter, width):
    counter = counter * 34
    x = 0
    y = 0
    while counter > width - 34:
        counter -= width - 34
        y+=1
    x = counter
    print("x: {} y: {}".format(x, y))
    return (x, y * 34)

def are_equal(img1, img2):
    width = img1.width
    height = img2.height
    for x in range(width):
        for y in range(height):
            pix1 = img1.getpixel((x, y))
            pix2 = img2.getpixel((x, y))
            if pix1 != pix2:
                return False
    return True

def is_in(curr, img_list):
    for img in img_list:
        if are_equal(img, curr):
            return True
    return False
        

if len(sys.argv) != 5:
    sys.exit()
    
img_name = sys.argv[1]
new_img_name = sys.argv[2]
new_width = int(sys.argv[3])
new_height = int(sys.argv[4])

img = Image.open(img_name)
width = img.width
height = img.height

new_img = Image.new(img.mode, (new_width, new_height))

curr = Image.new(img.mode, (34, 34))

img_list = []

counter = 0

for x in range(int(width / 32)):
    for y in range(int(height / 32)):
        for x2 in range(32):
            for y2 in range(32):
                pix = img.getpixel((x2 + x * 32, y2 + y * 32))
                curr.putpixel((x2, y2), pix)
##        if not is_in(curr, img_list):
        copy(new_img, curr, get_pos(counter, new_width))
        counter += 1
##            img_list.append(curr.copy())

new_img.save(new_img_name, "PNG")
