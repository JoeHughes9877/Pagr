# Pagr
<img width="1395" height="783" alt="image" src="https://github.com/user-attachments/assets/b4dac3d4-86aa-4382-ab49-989fae6abfd3" />

Pagr is a minimalist terminal-based eBook reader designed to provide a smooth, Kindle-like reading experience directly in your command line. It supports multiple formats including PDF, EPUB, Markdown, and plain text, with pagination, keyboard navigation, bookmarks, and more.

Currently only supports plaintext with plans for more in the future

---
# Motive

I like reading ebooks, but sometimes the formatting on Kindle can get weird when they are "borrowed" off the internet. So I made this to make it so I could read ebooks on my PC and laptop easier.

---

## Features

- 📄 Supports PDF, EPUB, Markdown, and plain text formats  
- 🔖 Paginated reading with page numbers and progress tracking  
- ⌨️ Keyboard navigation: next/previous page, jump to start/end, search  
- 🎨 Light and dark terminal themes  
- 💾 Save and restore last-read page automatically  
- ⚡ Fast and lightweight — works in any terminal  

---

## Installation

Build and install Pagr using `make`:

```bash
git clone JoeHughes9877/Pagr
cd pagr
make
sudo make install

```
## Keybinds

| Key | Action                |
|-----|-----------------------|
| `n` | Next page             |
| `b` | Previous page         |
| `g` | Go to start of book   |
| `G` | Go to end of book     |
| `q` | Quit                  |

