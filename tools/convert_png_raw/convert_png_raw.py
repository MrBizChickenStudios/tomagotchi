from PIL import Image
import struct
import os

# script folder
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))

# folders
INPUT_DIR = os.path.join(SCRIPT_DIR, "input")
DATA_DIR = os.path.abspath(os.path.join(SCRIPT_DIR, "../../data"))

# make data dir if missing
os.makedirs(DATA_DIR, exist_ok=True)

# loop through input folder
for filename in os.listdir(INPUT_DIR):

    if not filename.lower().endswith((".png", ".jpg", ".jpeg")):
        continue

    input_path = os.path.join(INPUT_DIR, filename)

    base_name = os.path.splitext(filename)[0]
    output_path = os.path.join(DATA_DIR, f"{base_name}.raw")

    img = Image.open(input_path).convert("RGB")

    with open(output_path, "wb") as f:
        for y in range(img.height):
            for x in range(img.width):
                r, g, b = img.getpixel((x, y))

                rgb565 = ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3)

                f.write(struct.pack(">H", rgb565))

    print(f"Converted: {filename} -> {output_path}")