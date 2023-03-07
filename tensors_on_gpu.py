import tensorflow as tf

randomTensor = tf.random.normal((10, 128), dtype=tf.float32)
tensor = tf.Variable(randomTensor, dtype=tf.float32, shape=(None, None))

print("before reshape : ", tensor)


def changeRowColumnTensor(rows, cols):

    tensor.assign(tf.zeros((rows, cols), dtype=tf.float32))


rows = int(input("Enter number of rows : "))
cols = int(input("Enter number of columns : "))

changeRowColumnTensor(rows, cols)

print("after reshape : ", tf.size(tensor))
print("after reshape : ", tensor)


print(tensor.device)