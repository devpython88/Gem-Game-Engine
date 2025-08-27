import os, shutil
import os.path as p
import sys

build_sys = input('Enter build system name (Unix Makefiles): ')

dist_dir = input('Enter distribution directory name: ')

def mkdir(name):
    if not p.exists(name):
        os.mkdir(name)

print("creating directories...")
mkdir('build')
mkdir(f'build/{dist_dir}')
mkdir(f'build/{dist_dir}/lib')
mkdir(f'build/{dist_dir}/include')

print("building...")

os.system(f'cmake -G {build_sys} -S . -B build')

if os.system(f'cmake --build build') != 0:
    print("failed to build.")
    exit(1)

print("copying..")

shutil.copy("build/libGem.a", f'build/{dist_dir}/lib')

shutil.copytree('src/Gem', f'build/{dist_dir}/include/Gem')

print("done.")