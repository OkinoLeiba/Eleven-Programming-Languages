#!/usr/bin/env bash

declare -a nums=(3, 2, 2, 3, 2, 0);
nums=(3, 2, 2, 3, 2, 0);
val=3


function removeElement(){
	# echo ${#1[@]};
	local num=#1;
	echo ${#num[@]};
	for i in {0...${#1[*]}}; do
		if [$i -eq $2]; then
			echo @0[$i]
			
		fi
	done
}

removeElement $nums $val