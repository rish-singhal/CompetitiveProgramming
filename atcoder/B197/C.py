s=input()
print("YNeos"[not(s[1::2]==s[1::2].upper() and s[::2]==s[::2].lower())::2])