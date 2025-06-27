# ee1520_s2025 hw1
## Programs

- `ee1520_Break`: Break a file into fixed-size chunks and create the meta file.
- `ee1520_Heal`: Reconstruct the full file by the information given in meta file.
- `Heal_with_holes`: Reconstruct only the first and last chunk into a sparse file.

## MakeFile

`make -f Makefile`: compile and link ee1520_Break.c ee1520_Heal.c Heal_with_holes.c

`make -f Makefile clean`: remove ee1520_Break* ee1520_Heal* Heal_with_holes*

## Run the programs (Part1)

`make -f Makefile`

`./ee1520_Break <input_file> <chunk_prefix> <chunk_size_in_KB>`

`./ee1520_Heal <output_file> <meta_file>`

`diff <output_file> <input_file>` : show the difference between the files

## Run the programs (Part2)

`./Heal_with_holes <output_file> <meta_file>`

`ls -l <output_file>` : virtual file size

`du -h <output_file>` : disk usage