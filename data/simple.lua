mesh = {}
mesh.name = 'Plane'
mesh.vertices = {}
mesh.faces = {}
mesh.location = {x=0.0,y=0.0,z=0.0}
mesh.rotation = {w=1.0,x=0.0,y=0.0,z=0.0}
mesh.scale = {x=1.0,y=1.0,z=1.0}
table.insert(mesh.vertices,{x=-1.0,y=-1.0,z=0.0})
table.insert(mesh.vertices,{x=1.0,y=-1.0,z=0.0})
table.insert(mesh.vertices,{x=-1.0,y=1.0,z=0.0})
table.insert(mesh.vertices,{x=1.0,y=1.0,z=0.0})
face = {}
  face.normal = {x=0.0,y=0.0,z=1.0}
  face.indexes = {0,1,3}
  table.insert( mesh.faces, face )
face = {}
  face.normal = {x=0.0,y=0.0,z=1.0}
  face.indexes = {3,2,0}
  table.insert( mesh.faces, face )
face = nil
meshes[mesh.name] = mesh
mesh = nil
