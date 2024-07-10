import chess
board = chess.Board()

# Print the initial board
print("Initial Board:")
print(board)
print("\nMaking a move: e2e4")
board.push_san("e4")
print(board)
