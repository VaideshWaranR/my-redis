# Redis-like Key-Value Store

A lightweight, Redis-inspired key-value store implementation written in C. This project provides an in-memory database server that supports basic Redis commands over TCP connections.

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

## Integration Examples

### Python Client
```python
import socket

def send_command(command):
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.connect(('localhost', 6379))
    sock.send(command.encode())
    response = sock.recv(1024).decode()
    sock.close()
    return response

# Usage
print(send_command("SET user:1 Alice"))
print(send_command("GET user:1"))
```

### Node.js Client
```javascript
const net = require('net');

function sendCommand(command) {
    return new Promise((resolve, reject) => {
        const client = net.createConnection(6379, 'localhost');
        
        client.on('connect', () => {
            client.write(command);
        });
        
        client.on('data', (data) => {
            resolve(data.toString());
            client.end();
        });
        
        client.on('error', reject);
    });
}

// Usage
sendCommand('SET user:1 Alice').then(console.log);
sendCommand('GET user:1').then(console.log);
```

### Curl (HTTP wrapper needed)
If you add HTTP support, you could use:
```bash
curl -X POST http://localhost:6379/command -d "SET key value"
curl -X GET http://localhost:6379/key
```

## Architecture

- **Single-threaded**: Handles one connection at a time
- **In-memory storage**: Uses hash tables for O(1) key lookups
- **TCP protocol**: Standard socket communication
- **Command parsing**: Custom protocol parser for Redis-like commands

## Project Structure

```
├── src/
│   ├── main.c          # Server entry point
│   ├── commands.c      # Command implementations
│   ├── storage.c       # Key-value storage logic
│   ├── network.c       # TCP server implementation
│   ├── parser.c        # Command parsing
│   └── Makefile        # Build configuration
├── README.md
└── LICENSE
```

## Performance

- **Memory-based**: Extremely fast read/write operations
- **No disk I/O**: Operations complete in microseconds (except SAVE)
- **Lightweight**: Minimal memory footprint
- **Scalable**: Handles thousands of operations per second

## Limitations

- **Single-threaded**: No concurrent connection handling
- **Volatile storage**: Data lost on restart (unless SAVE is used)
- **Basic persistence**: Simple file-based persistence
- **Limited commands**: Subset of Redis functionality

## Development

### Building in Debug Mode
```bash
make debug
```

### Cleaning Build Files
```bash
make clean
```

### Running Tests
```bash
make test
```

## Contributing

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Add tests if applicable
5. Submit a pull request

## Roadmap

- [ ] Multi-threading support
- [ ] Additional Redis commands (INCR, DECR, etc.)
- [ ] Persistent storage improvements
- [ ] Configuration file support
- [ ] Clustering support
- [ ] Memory optimization

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Acknowledgments

- Inspired by Redis
- Built for educational and lightweight use cases
- Thanks to the open-source community

---

**Note**: This is a simplified Redis implementation intended for learning and lightweight applications. For production use cases requiring high availability, clustering, or advanced features, consider using the official Redis server.
