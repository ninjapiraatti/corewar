.name "Corny Corellian"
.comment "I'm about to scare a neurasthenic hedgehog"

basic:
	st		r1, r8
	st		r1, 6
	live	%42
	fork	%:floof

floof:
	st		r1, 6
	live	%42

loadfloof:
	st		r1, 35
	st		r1, 35
	st		r1, 35
	st		r1, 35
	st		r8, 35
	st		r1, 35
	st		r1, 35

livefloof:
	live	%5682
	live	%5682
	live	%5682
	live	%5682
	live	%5682
	live	%5682
	live	%5682
