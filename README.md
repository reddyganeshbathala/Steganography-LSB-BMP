# 🔒 Steganography-LSB-BMP  
*A C-based image steganography system using Least Significant Bit (LSB) encoding*

This project implements **image steganography** in C using the **Least Significant Bit (LSB)** technique to hide and retrieve secret files inside 24-bit BMP images without changing their visible quality.  
It supports encoding, decoding, magic string verification, and works across multiple platforms.

---

## ✅ Features
✔ Hide any type of file (`.txt`, `.c`, `.sh`, etc.) inside a BMP image  
✔ Extract the hidden file perfectly during decoding  
✔ Uses **Magic String (#*)** to ensure the image actually contains hidden data  
✔ Maintains original BMP image quality  
✔ Error handling for invalid inputs and file formats  
✔ Works on Windows, Linux, and macOS (GCC compatible)

---

## 📂 File Structure

| File | Description |
|------|-------------|
| `main.c` | Controls encoding/decoding flow and CLI |
| `encode.c / encode.h` | Logic for hiding data into the image |
| `decode.c / decode.h` | Logic for extracting hidden data |
| `types.h` | Custom data types and enums |
| `common.h` | Magic string (#*) used for validation |
| `secret.txt` | Example secret file |
| `Input_image.bmp` | Original BMP image |
| `Encoded_Image.bmp` | Output image with hidden data |
| `Decoded_File.txt` | Extracted file after decoding |

---

## 🚀 How It Works (Internals)
- Reads BMP header (54 bytes) without modification  
- Embeds magic string → file extension → file size → secret file data  
- Uses **LSB of each byte** so image quality remains unchanged  
- During decoding, verifies magic string, then reconstructs the hidden file

---

## 🔧 Requirements
- GCC or any standard C compiler  
- Windows / Linux / macOS terminal  
- 24-bit BMP image as input  

---

## 🛠 Usage

### Encoding
      ./steganography -e Original_input.bmp secret.txt
### Decoding
      ./steganography -d Encoded_Image.bmp
---

## ⭐ Support This Project
If this project helped you or you learned something new, please leave a ⭐ on GitHub — it motivates future work and improvements!

👉 **https://github.com/reddyganeshbathala/Steganography-LSB-BMP**

---

## 👤 Author
**Reddy Ganesh B**  
B.Tech, Electronics and Communication Engineering  
Passionate about Embedded Systems, C Programming & Real-world Projects

🔗 **LinkedIn:** https://www.linkedin.com/in/reddyganeshbathala 
🔗 **GitHub:** https://github.com/reddyganeshbathala

---

