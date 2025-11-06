from setuptools import setup, Extension

module = Extension('sim', sources=['sim.c'])

setup(name='sim',
      version='1.0',
      description='Simple IoT sensor simulation',
      ext_modules=[module])
