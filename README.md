# 42: minitalk with bonus - 125/100
<p align="center">
  <img src="https://game.42sp.org.br/static/assets/achievements/minitalkm.png" alt="Achievement Image"><br>
</p>

This project is part of the curriculum at 42 School and aims to implement a client-server communication system using the UNIX signals. The goal is to create a simple chat application where a client can send messages to a server.

## Overview

The Minitalk project is a network communication project that involves two main components: a client and a server. The client is responsible for sending messages to the server, while the server receives and displays the messages.

The communication between the client and server is achieved using UNIX signals. The client converts each character of the message into a binary representation and sends it to the server using the SIGUSR1 and SIGUSR2 signals. The server receives the signals, converts the binary representation back into characters, and displays the received message.

The project requires the implementation of both the client and server programs, as well as handling various edge cases and error conditions. It also involves handling signal handling and synchronization between the client and server processes.

## Table of Contents

- [Getting Started](#getting-started)
- [Features](#features)
- [Usage](#usage)

## Getting Started

To get started with the Minitalk project, follow these steps:

1. Clone the project repository:
	```bash
	git clone https://github.com/brmoretti/42_minitalk.git
	```
2. Compile the client and server programs using the provided Makefile. Run the following command in the terminal:
	```bash
	make
	```

## Features

The Minitalk project includes the following features:

- Client-server communication using UNIX signals
- Conversion of characters to binary representation
- Error handling and edge case management
- Synchronization between client and server processes

## Usage

To use the Minitalk chat application, follow these steps:

1. Start the server by running the following command in the terminal. This will display the process ID of the server:
	```bash
	./server
	```
2. Start the client by running the following command in the terminal:
	```bash
	./client [server_pid] [message]
	```
	Replace `[server_pid]` with the process ID of the server and `[message]` with the message you want to send. **Unicode characters are supported.**🔡💻🔤

3. The server will display the received message in the terminal.

4. To stop the server, press `Ctrl + C` in the terminal.
