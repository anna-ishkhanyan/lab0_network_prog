# Simple HTTP Client in C

This program is a basic HTTP client written in C that connects to a remote server using sockets, sends a GET request, and displays the response.

## Features

- Creates a TCP socket
- Connects to `parliament.am` (IP: `147.182.222.214`) over port 80
- Sends a simple HTTP GET request for `/` with `Host: aua.am`
- Receives and prints the HTTP response from the server

## Usage

### Compile
```bash
gcc -o http_client client_http.c
