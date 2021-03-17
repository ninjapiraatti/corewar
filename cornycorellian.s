.name "Corny Corellian"
.comment "I'm about to scare a neurasthenic hedgehog"

basic:
	st		r1, r8
	st		r1, 6
	live	%42
	fork	%:basic

floof:
	st		r1, 6
	live	%42

load:
	st		r1, 36
	st		r1, 36
	st		r1, 36
	st		r1, 36
	st		r8, 36
	st		r1, 36
	st		r1, 36

live:
	live	%5682
	live	%5682
	live	%5682
	live	%5682
	live	%5682
	live	%5682
	live	%5682

expand:
	ld 		%1, r10
	st		r10, 242
	st		r1, 241
