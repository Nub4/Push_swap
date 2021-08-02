# Push_swap
Validated 27.5.2021\
Points 111/100

# Setups:
1. Go to Checker folder and create Checker launcher to Push_swap folder with "make"\
2. Go to Push_swap folder and create Push_swap launcher with "make"

# Using the program:
To check if it sorting the list use this command (this creates 500 numbers in random order):\
ARG="`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`" ; ./push_swap $ARG | ./checker $ARG\

To check how many lines it takes to sort the list:\
ARG="`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`" ; ./push_swap $ARG | wc -l
