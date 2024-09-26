
import re

bogus_char = "X"

def insert_x_between_identical_letters(text):
    # Use regex to match any two consecutive identical letters
    result = re.sub(r'(\w)\1', r'\1'+bogus_char+r'\1', text)
    return result

# Test the function
text = "letter cool balloon"
modified_text = insert_x_between_identical_letters(text)
print(modified_text)
