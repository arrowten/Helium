DIR="tests" #Folders with all the test cases
EXT="hel" #File extension to process
OUT_DIR="outputs"
NEW_EXT="txt" #File extension to save output

#Ensuring the output directory exists
mkdir -p "$OUT_DIR"

#Looping through all files with the given extension
for file in "$DIR"/*."$EXT"; do
    # Check if there are any matching files
    echo '\n'
    if [ -e "$file" ]; then
        #Take out the file name without extension
        base_filename=$(basename "$file" ".$EXT")
        #Make an output file in the output directory
        output_file="$OUT_DIR/$base_filename.$NEW_EXT"
        ./_build/Helium "$file" | tee "$output_file"
    else
        echo "No files with the extension .$EXT found."
        break
    fi
done