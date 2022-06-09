from setuptools import setup

package_name = 'example_py_pkg'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='dhruv',
    maintainer_email='dhruv@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "ex_py_1 = example_py_pkg.ex_py_1:main",
            "ex_py_2 = example_py_pkg.ex_py_2:main",
            "ex_py_pub_server = example_py_pkg.ex_py_pub_server:main",
            "ex_py_sub_client = example_py_pkg.ex_py_sub_client:main"
        ],
    },
)
