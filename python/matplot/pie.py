
lables = ['a', 'b', 'c']
data = [10, 2, 5]
plt.pie(data, labels = lables)
plt.pie(data, labels = lables, autopct='%1.1f%%')
plt.axis('equal')
plt.legend()