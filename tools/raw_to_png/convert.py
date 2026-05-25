from PIL import Image
import struct

WIDTH = 320
HEIGHT = 240

img = Image.new("RGB", (WIDTH, HEIGHT))
pixels = []

with open("screen.raw", "rb") as f:
    for _ in range(WIDTH * HEIGHT):

        # Read 2 bytes
        b = f.read(2)

        # Little-endian RGB565
        pixel = struct.unpack("<H", b)[0]

        # Swap bytes
        pixel = ((pixel & 0xFF) << 8) | (pixel >> 8)

        r = ((pixel >> 11) & 0x1F) * 255 // 31
        g = ((pixel >> 5) & 0x3F) * 255 // 63
        b = (pixel & 0x1F) * 255 // 31

        pixels.append((r, g, b))

img.putdata(pixels)
img.save("screen.png")

print("Saved screen.png")