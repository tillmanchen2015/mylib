

x = np.arange(7)
data = np.arange(7)
# a trick to generate color matrix
# 21 data reshape to 7 rows and 3 cols. 3 cols represents RGB
colors = np.random.rand(7 * 3).reshape(7, -1)
labels = ['Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat', 'Sun']
 
plt.title("Weekday Data")
plt.bar(x, data, alpha=0.8, color=colors, tick_label=labels)
plt.show()