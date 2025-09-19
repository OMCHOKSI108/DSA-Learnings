# 192. Word Frequency
# Medium
# Topics
# premium lock icon
# Companies

# Write a bash script to calculate the frequency of each word in a text file words.txt.
# For simplicity sake, you may assume:
# words.txt contains only lowercase characters and space ' ' characters.
# Each word must consist of lowercase characters only.
# Words are separated by one or more whitespace characters.

# Example:
# Assume that words.txt has the following content:
# the day is sunny the the
# the sunny is is
# Your script should output the following, sorted by descending frequency:
# the 4
# is 3
# sunny 2
# day 1

------------------------------------------------------------------------------------

declare -A freq
 
while IFS= read -r line; do
    
    for word in $line; do
        
        ((freq["$word"]++))
    done
done < words.txt
 
for word in "${!freq[@]}"; do
    echo "$word ${freq[$word]}"
done | sort -k2 -nr