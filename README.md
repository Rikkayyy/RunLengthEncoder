# Run Length Encoder (RLE) Decoder

A C++ program that decodes Run Length Encoded (RLE) messages from a file. Built as a University of Houston computer science project.

## What It Does

Run Length Encoding compresses repeated characters by storing the character once along with how many times it repeats. This program reads RLE-encoded messages from a file and reconstructs the original strings.

The encoding scheme used here marks repeated characters by **doubling** them in the RLE string, with the run lengths stored separately in a frequency list.

**Example:**

```
RLE String:   BWWBBWWBWWWW
Frequencies:  12 12 3 24 14
Decoded:      B + (W×12) + BB + (W×12) + B + (W×24) + (W×14)...
```

## Project Structure

```
RunLengthEncoder/
├── main.cpp          # Entry point
├── RLEDecoder.h/.cpp # Reads file, decodes messages, prints output
├── RLEInfo.h/.cpp    # Stores an RLE string and its frequency vector
└── input.txt         # Sample input file
```

## Input File Format

The input file alternates between two line types:

```
<RLE string>
<count> <freq1> <freq2> ...
```

- **RLE string** — the encoded message (doubled characters indicate a run)
- **count** — number of frequencies that follow
- **freq values** — how many times each doubled character repeats

**Example `input.txt`:**

```
BWWBBWWBWWWW
5 12 12 3 24 14
00100110011001
6 10 11 3 15 2 19
```

## How to Compile and Run

```bash
g++ main.cpp RLEDecoder.cpp RLEInfo.cpp -o rle
```

Then run it and provide the number of messages and the input filename:

```bash
echo "4 input.txt" | ./rle
```

Or interactively:

```bash
./rle
4
input.txt
```

## Sample Output

```
RLEString: BWWBBWWBWWWW
RLEFrequencies: 12 12 3 24 14

Decoded Message 1: B...

RLEString: 00100110011001
RLEFrequencies: 10 11 3 15 2 19

Decoded Message 2: 0...
```

## Classes

### `RLEInfo`
Stores a single RLE entry — the encoded string and its frequency vector.

### `RLEDecoder`
Manages an array of `RLEInfo` objects. Handles:
- Reading and parsing the input file
- Decoding each RLE message
- Printing encoded info and decoded results

Implements the Rule of Three: copy constructor, copy-assignment operator, and destructor.
