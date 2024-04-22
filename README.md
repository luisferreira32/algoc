# Algorithmic C - Competitive Programming

A log book of a newly found hobby.

We follow the C way here.

## Make it work

First command to run is: `make setup`.

To run a test solution you only need to run `make <problem_name>`. This will run the binary and attempt to do what the problem explanation requests of the algorithm, e.g., if it expects certain input on standard input, will wait to read that input, if it expects a file in a certain location, will try to read from that location.

For example, to run the Code forces problem 96A "Football" utilize the make target:
```bash
$ make football
```

There are also automated tests constructed based on the problem statements. To run those tests for a certain problem, you only need to run `make out/<problem_name>`.

For example, to run automated tests for the Code forces problem 96A "Football" utilize the make target:
```bash
$ make out/football
```

## Code forces

Submissions for the problem set in: [codeforces.com/problemset](https://codeforces.com/problemset)

Problem | File
------- | ----
4A      | watermelon.c
71A     | watermelon.c
231A    | team.c
282A    | bitplusplus.c
96A     | football.c
1165B   | polycarptraining.c
58A     | chatroom.c
158B    | taxi.c
270A    | fancyfence.c
466A    | cheaptravel.c
1520D   | samedifferences.c
