from setuptools import setup, Extension
import pybind11
import fnmatch
import os

__version__ = '0.1.0'

sources = ["src/"+fname for fname in os.listdir("src") if fnmatch.fnmatch(fname, '*.cpp')]

ext_modules = [
    Extension(
        'xo_app',
        # Sort input source files to ensure bit-for-bit reproducible builds
        # (https://github.com/pybind/python_example/pull/53)
        sorted(['python/python_wrapper.cpp']+sources),
        include_dirs=[
            # Path to pybind11 headers
            pybind11.get_include(), 'src'
        ],
        language='c++'
    ),
]

setup(
    name='xo_app',
    version=__version__,
    author='Denis Shihalev',
    author_email='shihalev.denis@gmail.com',
    url='https://github.com/mouseMD/xo_app',
    description='XO Game base logic',
    long_description='',
    ext_modules=ext_modules,
    setup_requires=['pybind11>=2.5.0']
)
