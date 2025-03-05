# Compile the project:
make

# Run the program:
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]

number_of_philosophers: The number of philosophers sitting at the table (1-200).
time_to_die: The time (in milliseconds) a philosopher can spend without eating before dying.
time_to_eat: The time (in milliseconds) it takes for a philosopher to eat.
time_to_sleep: The time (in milliseconds) a philosopher spends sleeping between meals.
number_of_times_each_philosopher_must_eat (optional): The number of times each philosopher must eat before the simulation ends.

# Example Usage:
./philo 4 800 200 200 5
