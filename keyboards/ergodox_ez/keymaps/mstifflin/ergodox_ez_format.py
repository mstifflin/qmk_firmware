# Usage python keyboards/ergodox_ez/keymaps/mstifflin/ergodox_ez_format.py | pbcopy

def format_ergodox_ez(key_code_string):
  kc = key_code_string.replace(" ", "").replace("\n", "").split(",")
  if len(kc) != 76:
    print("Error, invalid number of key codes: " + str(len(kc)))
    return
  matrix, max_len = create_matrix(kc)
  formatted_matrix = format_matrix(matrix, max_len)
  print_matrix(formatted_matrix)
  return

def create_matrix(kc):
  length_config = [7, 7, 6, 7, 5, 2, 1, 3]
  matrix = []
  max_len = 0
  i = 0
  for _ in range(2):
    for length in length_config:
      line = []
      for index in range(i, i + length):
        if max_len < len(kc[index]):
          max_len = len(kc[index])
        line.append(kc[index])
      i = i + length
      matrix.append(line)

  return matrix, max_len

def format_matrix(matrix, max_len):
  for i in range(len(matrix)):
    for j in range(len(matrix[i])):
      if len(matrix[i][j]) < max_len:
        matrix[i][j] += " " * (max_len - len(matrix[i][j]))

  return matrix

def print_matrix(matrix):
  output = "// Left hand\n"

  for i in range(8):
    output += ", ".join(matrix[i]) + ",\n"

  output += "\n// Right hand\n"
  for i in range(8, 16):
    output += ", ".join(matrix[i]) + ",\n"

  print(output[:-2])


format_ergodox_ez(""" """)
