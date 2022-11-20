#importing the model
import modeltrain

from everywhereml.code_generators.tensorflow import tf_porter

tf_model, x_train, y_train = get_model()
cpp_code = tf_porter(tf_model, x_train, y_train).to_cpp(instance_name='cartkeepNN')

print(cpp_code)
