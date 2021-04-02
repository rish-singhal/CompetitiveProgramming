I = input
exec(int(I())*"n,k=map(int,I().split());s=I();print('YNEOS'[s[:k]!=s[:~k:-1] or 2*k==n::2]);")

