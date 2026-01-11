# Inverted Search Engine (C)

This project implements an **Inverted Search Engine** in C using **hash tables and linked lists**.  
It indexes words from multiple text files and allows efficient searching of words across files.

---

## 📌 Features

- File verification (existence, empty file check, duplicate file handling)
- Create inverted index database from multiple input files
- Display the complete database
- Search a word and list files where it appears
- Update database by adding new files without rebuilding
- Save database contents to a text file
- Uppercase and lowercase words are stored separately but mapped to the same index

---

## 🧠 Data Structures Used

- Hash Table (26 indices for alphabets)
- Singly Linked Lists
  - Main node: stores each unique word
  - Sub node: stores file-wise word count
- Linked list for managing verified file names

---

## ⚙️ Working Principle

1. Input files are verified for validity and duplication.
2. Words are extracted character by character.
3. Hash index is calculated using the first character of the word.
4. Each word is stored in the hash table with a list of files in which it appears.
5. Update operation processes only newly added files.

---

## 🖥️ Menu Options

1.CREATE DATABASE

2.DISPLAY DATABASE

3.SEARCH DATABASE

4.UPDATE DATABASE

5.SAVE

6.EXIT

---

## ▶️ How to Compile and Run

### Compile
gcc *.c

### Run
./a.out file1.txt file2.txt file3.txt

---

## 💾 Output

- Search results are displayed on the terminal
- Database contents can be saved to `DATABASE.txt`

---

## 📂 Project Structure

├── main.c
├── common.h
├── data_base.c
├── insert_word.c
├── file_verification.c
├── display.c
├── search.c
├── save.c
├── file1.txt
├── file2.txt
├── file3.txt

---

## 👨‍💻 Author

Sugavelan G







