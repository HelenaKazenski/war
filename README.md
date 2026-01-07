# **war**

War is a C++ project that implements a reusable standard playing card deck and applies it to a playable simulation of the card 
game *War* against a computer opponent. The project emphasizes object-oriented design, dynamic memory management, algorithmic 
logic, and memory safety, with validation using Valgrind.

# **Features**

- Standard 52-card deck implementation
- Object-oriented **Deck**, **StandardDeck**, and **Card** design
- Dynamic memory management with proper constructor and destructor logic
- Randomized deck shuffling
- Support for merging and managing multiple decks
- Fully playable War game simulation against a computer opponent
- Automated gameplay with score tracking and win determination
- Memory leak detection and validation using Valgrind

# **How It Works**

**Standard Card Deck:**
- The *StandardDeck* class dynamically creates and manages a 52-card deck
- Supports shuffling, dealing cards, merging decks, and displaying cards
- Designed to be reusable for multiple card-based games

**War Game Simulation:**
- A shuffled deck is split evenly between the player and the computer
- Players alternate drawing cards and placing them on the battleground
- When two cards of equal face value are played consecutively, the current player wins the battleground and collects all cards
- The game continues until one player runs out of cards or a turn limit is reached
- Final scores are determined by remaining card counts, and a winner is declared

# **Technologies Used**

- **Language:** C++
- **Concepts:**
  - Object-Oriented Programming (OOP)
  - Dynamic memory management
  - Constructors and destructors
  - Algorithmic game simulation
  - Data structures *(std::vector)*
- **Tools:**
  - Git & GitHub
  - Valgrind (for memory leak detection and debugging)

# **Challenges & Solutions**

**Dynamic Memory Management:**
- Managing decks via pointers introduced the risk of memory leaks. This was addressed by implementing proper destructor logic
and verifying correct allocation and deallocation using Valgrind.

**Game State Management:**
- Tracking turns, battleground cards, and player decks required careful control flow. This was solved using clear turn logic and
a battleground vector to manage contested cards.

**Fair Card Distribution and Shuffling:**
- Ensuring an unbiased shuffle and even distribution was handled through randomized shuffling followed by alternating card
dealing.

**Infinite Game Prevention:**
- To avoid endless gameplay, a turn limit was enforced while still allowing the game to reach a meaningful outcome.

# **What I Learned**

- Designing reusable C++ classes for card-based systems
- Managing dynamic memory safely in non-trivial applications
- Simulating turn-based games using algorithmic logic
- Using Valgrind to detect and resolve memory leaks
- Writing maintainable, modular C++ code

# **What's Next**

- Add user interaction for manual gameplay
- Implement full War rules (multi-card wars)
- Refactor to use smart pointers *(std::unique_ptr)*
- Expand the deck system for additional card games

# **Conclusion**

This project was completed in September 2025 as part of a C++ programming course. It reinforced core systems programming
concepts, including object-oriented design, dynamic memory management, and algorithmic problem-solving, while demonstrating how
reusable components can support complete game simulations.

# **Credits**

- Created by Helena Kazenski (September 2025)
