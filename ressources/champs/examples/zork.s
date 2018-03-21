.name "A"
.comment "A"

l2:		sti r5, %:live, %5
		aff r15
		lfork   %2957
		lldi    %42, %42, r16
		lld	%:live, r5
		fork %:live
		and r5, %5, r5

live:	live %5
		zjmp %:live
