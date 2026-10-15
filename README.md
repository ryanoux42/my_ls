# 📁 MY_LS

## Description

**MY_LS** is a re-implementation of the Unix command **`ls`**, written in **C**.  
It lists the content of directories and displays information about files, using only low-level system calls such as `opendir`, `readdir`, `stat` / `lstat`, `getpwuid` and `getgrgid`.

This project focuses on **file system manipulation**, **file metadata**, **permissions**, **recursion** and **argument parsing**.

---

## 🧩 Features

| Flag | Description |
|------|-------------|
| *(none)* | List the current directory |
| `-a` | Show hidden files (starting with `.`) |
| `-l` | Long listing: permissions, links, owner, group, size, date |
| `-R` | List sub-directories recursively |
| `-d` | List the directory itself, not its content |
| `-r` | Reverse the sort order |
| `-t` | Sort by modification time |

- Flags can be **combined** (`-la`, `-lR`, ...)
- Works on **files and directories** given as arguments
- Error handling on invalid flags and missing files (exit code `84`)

---

## ⚙️ Usage

### Compilation

```bash
make
```

Other rules:
```bash
make re      # Rebuild everything
make clean   # Remove object files
make fclean  # Remove binaries and object files
```

---

### Execution

```bash
./my_ls [-alRdrt] [FILE...]
```

#### Example:
```bash
./my_ls
./my_ls -la
./my_ls -R lib
./my_ls -l my_ls.c
```

---

## 🎯 Learning Objectives

- Read directories with `opendir` / `readdir`
- Get file metadata with `stat`
- Format permissions (`drwxr-xr-x`) and dates
- Handle recursive traversal
