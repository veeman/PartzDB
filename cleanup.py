import os
import sys
import shutil

for root, dirs, files in os.walk('.', True):
    if root in ['.\_Debug', '.\_Release', '.\_lib', '.\ipch', '.\Doxygen\out'] or \
        'GeneratedFiles' in root:
        shutil.rmtree(root)

    for file in files:
        name, ext = os.path.splitext(file)
        if ext in ['.sdf', '.user', '.aps']:
            os.remove(os.path.join(root, file))

