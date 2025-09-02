# Steganography-LSB-BMP

A C-based implementation of **image steganography** using the **Least Significant Bit (LSB)** technique to securely hide and retrieve files within 24-bit BMP images without altering their visual quality.

## 📜 Abstract
Steganography is the art of concealing information within non-secret media to avoid detection.  
This project implements LSB-based steganography in C to hide a secret file inside a BMP image and retrieve it later.  
The system supports both **encoding** and **decoding**, ensures data integrity using a magic string, and preserves the image’s appearance.

---

## 📂 Features
- **Encode Secret Files** – Hide any file (text, code, scripts) inside a BMP image.
- **Decode Hidden Files** – Extract hidden files from stego images.
- **Magic String Verification** – Confirms the presence of hidden data.
- **Supports Multiple File Types** – Works with `.txt`, `.c`, `.sh`, etc.
- **Error Handling** – Clear success and failure messages.
- **Data Integrity** – Ensures extracted data matches the original.
- **Cross-Platform** – Works on Windows, Linux, and macOS.

---

## 🛠 Requirements
**Software:**
- OS: Windows / Linux / macOS
- Compiler: GCC or any standard C compiler
- Editor/IDE: Code::Blocks, VS Code, Turbo C, Vim, etc.
- Terminal: Command Prompt / Linux Terminal / macOS Terminal

---

## 🚀 Usage

### Encoding
      ./steganography -e Original_input.bmp secret.txt
### Decoding
      ./steganography -d Encoded_Image.bmp
---
## 📄 Full Project Report
📥 [Download the Full Report](Project_Report.pdf)
---
