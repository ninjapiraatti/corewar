.name "tester"
.comment "i'm tester champion"

label:
double_label: sti r1, %:komento, %1



		and r1, %:label, r1

komento:
		live %1
		zjmp %:komento
