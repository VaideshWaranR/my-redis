# Redis-like Key-Value Store

A lightweight, Redis-inspired key-value store implementation written in C. This project provides an in-memory database server that supports basic Redis commands over TCP connections.

┌─────────────────────────────────────────────────────────────┐
│                    Development Environment                  │
├─────────────────────────────────────────────────────────────┤
│  📝 vim      →  Code editor of choice                       │
│  ⚡ C        →  Pure system programming language            │
│  🪟 tmux     →  Terminal multiplexer for workflow           │
│  🔌 telnet   →  Testing TCP connections                     │
└─────────────────────────────────────────────────────────────┘
## Features

- **In-memory storage**: Fast key-value pair storage in RAM
- **TCP server**: Runs on localhost:6379 (standard Redis port)
- **Redis-compatible commands**: Supports core Redis operations
- **Socket-based communication**: Easy integration with various tech stacks
- **Lightweight**: Minimal dependencies, written in pure C

## Supported Commands

| Command | Description | Usage |
|---------|-------------|-------|
| `set` | Store a key-value pair | `set key value` |
| `get` | Retrieve value by key | `get key` |
| `del` | Delete a key-value pair | `del key` |
| `exists` | Check if key exists | `exists key` |
| `clear` | Remove all key-value pairs | `clear` |
| `save` | Persist data to disk | `save` |

## Installation

### Prerequisites

- GCC compiler
- Make utility
- POSIX-compatible system (Linux, macOS, WSL)

### Build Instructions

1. **Clone the repository**
   ```bash
   git clone https://github.com/VaideshWaranR/my-redis
   cd <project-directory>
   ```

2. **Navigate to source directory**
   ```bash
   cd src
   ```

3. **Compile the project**
   ```bash
   make all
   ```

4. **Run the server**
   ```bash
   ./app
   ```

The server will start and listen on `localhost:6379`.

## Usage

### Starting the Server

```bash
cd src
make all
./app
```

You should see output indicating the server is running:
```
Server listening on localhost:6379
```

### Connecting to the Server

You can connect to the server using various methods:

#### Using telnet
```bash
telnet localhost 6379
```

#### Using netcat
```bash
nc localhost 6379
```

### Example Session

```bash
$ telnet localhost 6379

set name JohnDoe
OK

get name
JohnDoe

exists name
1

del name
OK

get name
(nil)

clear
OK

SAVE
OK
```

