# Pagr

![Pagr Terminal eBook Reader](docs/example-screenshot.png)

**Pagr** is a minimalist terminal-based eBook reader designed to provide a smooth, Kindle-like reading experience directly in your command line. It supports multiple formats including PDF, EPUB, Markdown, and plain text, with pagination, keyboard navigation, bookmarks, and more.

---
## Motive
I Like reading ebooks but sometimes the formatting on kindle can get weird when they are "borrowed" of the internet. So i made this to make it so i could read ebooks on my PC and laptop easier.
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
git clone https://github.com/yourusername/pagr.git
cd pagr
make
sudo make install

```
## Keybinds

| Key | Action                |
|-----|-----------------------|
| `n` | Next page             |
| `p` | Previous page         |
| `g` | Go to start of book   |
| `G` | Go to end of book     |
| `q` | Quit                  |

