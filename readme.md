# Roulette Game in C++

This project is a simple terminal-based Roulette game implemented in C++. Players can bet on numbers, colors, or parity (even/odd) and play multiple rounds, all while maintaining a balance. The game also logs the results of each round.

## Features

1. **Bet Types**:
   - **Number**: Bet on a specific number (0–36).
   - **Color**: Bet on Red or Black.
   - **Parity**: Bet on Even or Odd.
2. **Balance Management**:
   - Players start with an initial balance of $1000.
   - Bets are deducted from the balance, and winnings are added back.
3. **Round Logs**:
   - Each round's results (win/loss) are logged and displayed at the end of the session.
4. **Randomized Outcomes**:
   - The roulette wheel generates random numbers (0–36).
   - Each number corresponds to a color (Red/Black/Green).

## How to Play

1. **Start the Game**:
   - Compile and run the program using a C++ compiler (e.g., GDB Online Compiler).
2. **Place Your Bets**:
   - Choose the type of bet: number, color, or parity.
   - Enter the bet amount and your guess.
3. **Check Results**:
   - The game spins the roulette wheel and determines the outcome.
   - If you win, your balance increases according to the payout rate.
   - If you lose, your balance decreases by the bet amount.
4. **End the Game**:
   - Exit the game manually or when your balance reaches $0.
5. **View Logs**:
   - At the end of the game, view a summary of all rounds played.

## Payout Rates

| Bet Type   | Payout Multiplier |
|------------|-------------------|
| Number     | 35x               |
| Color      | 2x                |
| Parity     | 2x                |

## Running the Game

1. Copy the code into any C++ IDE or online compiler (e.g., GDB Online Compiler).
2. Compile the code:
   ```bash
   g++ -o roulette roulette.cpp
   ```
3. Run the compiled program:
   ```bash
   ./roulette
   ```
4. Follow the on-screen instructions to play.

## Sample Gameplay

### Game Start
```
🎲 Welcome to the Roulette Game! 🎲
Your starting balance: $1000
```

### Placing a Bet
```
Your current balance: $950
Choose your bet type:
1. Number (0–36)
2. Color (Red/Black)
3. Parity (Even/Odd)
4. Exit
Your choice: 2
Enter your bet amount: $50
Guess the color (Red/Black): Red
```

### Round Result
```
Result: Black
Sorry, you lost $50.
```

### Game End
```
Thank you for playing! Your final balance: $850

Game Logs:
1. Lost $50 on Color (Red). Winning color: Black.
2. Won $100 on Parity (Even). Winning number: 12.
```

## Requirements

- A C++ compiler (e.g., GCC, Clang).
- Basic knowledge of terminal or command-line interface.

## Future Improvements

1. **Add Statistics**:
   - Display win/loss ratio and most frequent outcomes.
2. **Advanced Betting**:
   - Include split bets, corner bets, and other roulette options.
3. **GUI Version**:
   - Implement a graphical interface using a library like SFML or Qt.
4. **Multiplayer Mode**:
   - Allow multiple players to join the game.

## License

This project is open-source and available under the MIT License. Feel free to modify and distribute it!
