# 68. Text Justification
# https://leetcode.com/problems/text-justification/

###################################################################################################
#
#   def formatLast(words, width):
#   1.  Return word + " " in words + " " * (width - sum of word.length in words)
#
#   def formatPhrase(words, width):
#   1.  Initialize length to sum of word.length in words
#   2.  Initialize gaps to words.length - 1
#   3.  Initialize phrase to ""
#   4.  If words.length == 1:
#   5.      return word + " " * (width - length)
#   6.  For word in words:
#   7.      Append " " * ((width - length) / gaps) + word to phrase
#   8.  Return phrase
#
#   def fullJustify(words, maxWidth):
#   1.  Initialize empty arrays out, and phrase
#   2.  Initialize phrase length to 0
#   3.  For word in words:
#   4.      If phrase length + phrase.length + word.length > maxWidth:
#   5.          Append formatPhrase(phrase, maxWidth) to out
#   6.          Set phrase to [], phrase length to 0
#   7.      phrase length += word.length
#   8.      Append word to phrase
#   9.  Append formatLast(phrase, maxWidth) to out
#   10. Return out
#
#   Time complexity:    O(N) to justify each word
#   Space complexity:   O(N) to store formatted words
#
###################################################################################################
def formatPhrase(words, width):
    length = sum(len(word) for word in words)
    gaps = len(words) - 1
    phrase = ""

    if len(words) == 1:
        return words[0] + " " * (width - len(words[0]))

    phrase = words[0]
    for index, word in enumerate(words[1:]):
        # Add extra whitespace between words on the left
        if index < (width - length) % gaps:
            phrase += " " * ((width - length) // gaps) + " " + word
        else:
            phrase += " " * ((width - length) // gaps) + word

    return phrase

def formatLast(words, width):
    # Add whitespace between words
    phrase = " ".join(words)
    # Append remaining width of whitespaces to end of phrase
    return phrase + " " * (width - len(phrase))

def fullJustify(words, maxWidth):
    out = []
    phrase = []
    phraseLen = 0

    for word in words:
        if phraseLen + len(phrase) + len(word) > maxWidth:
            # Add formatted phrase to out
            out.append(formatPhrase(phrase, maxWidth))

            # Empty phrase
            phrase = []
            phraseLen = 0

        # Add word to phrase
        phraseLen += len(word)
        phrase.append(word)

    # Format and add last phrase
    out.append(formatLast(phrase, maxWidth))

    return out

# Test cases
words1 = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth1 = 16
print(fullJustify(words1, maxWidth1))

words2 = ["What", "must", "be", "acknowledgment", "shall", "be"]
maxWidth2 = 16
print(fullJustify(words2, maxWidth2))

words3 = ["Science", "is", "what", "we", "understand", "well", "enough", "to", "explain", "to", "a",
    "computer.", "Art", "is", "everything", "else", "we", "do"]
maxWidth3 = 20
print(fullJustify(words3, maxWidth3))
