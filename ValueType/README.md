
# General

|   | C Type       | What             | Bytes |
| - | ------------ | ---------------- | ----- |
| F | float        | Floating Point   | 4     |
| I | int          | Intager          | 4     |
| U | unsigned int | Unsigned Intager | 4     |

# Bool

Multi-Dimensional Bool<br>
packed into 1 Byte<br>

# Vector

These are Math Vectors.<br>
The Letter is the Type.<br>
The Number is the Dimension.<br>

### Unusual Functions

| Function Name | Description |
| ------------- | ----------- |
| Mix() | Takes Dimensional Bool.<br> false takes the Value from this, true takes the Value from other. |
| round() | normal Rounding |
| roundF() | Floor / round down |
| roundC() | Ceiling / round up |
| Product() | Product of Components |
| Convert(Vector)       | converts Dimensional Index to             Index of a Array[X,Y,Z] |
| Convert(Unit)         | converts             Index to Dimensional Index of a Array[X,Y,Z] |
| Convert(size, Vector) | converts Dimensional Index to             Index of a Array[size,size,size] |
| Convert(size, Unit)   | converts             Index to Dimensional Index of a Array[size,size,size] |

# Matrix

# Box

A Min Vector/Unit and a Min Vector/Unit.
So Axis aligned Boxes.

### Unusual Functions

| Function Name | Description |
| ------------- | ----------- |
| InverseLimit() | returns a Box where Min has the Maximum Type Value and Max has the Minimum Type Value. |
| Consider() | Min = Min.Min(vec);<br>Max = Max.Max(vec);<br> |
| IsNormal() | Is Min less then Max |
| ContainsEdge(vec)      | Is the given Vector on the Edge of the Box. |
| ContainsInclusive(vec) | Is the given Vector in the Box, including the Edge. |
| ContainsExclusive(vec) | Is the given Vector in the Box, excluding the Edge. |

## Composits

| Name | Notes |
| - | - |
| Line |  |
| Ray |  |
| Triangle |  |
| NormalPlane |  |
| Angle |  |
| EulerAngle | Order is: Z , X , Y |
| Trans | Order is: Position , Rotation |
| Color | U4 is 32 Bits |
| Light | basic Lights |
| Range | Min Value , Max Value and Distance between them |
| DepthFactors | Factors used for Calculating simple Depth.<br> This is a flat Plane from View, not a Sphere.<br> Should put these into the View Matrix or make a Depth Matrix |
| Depth | DepthFactors along with Range of where Depth Fades and the Color that Depth fades to. |

# Interact

Some Intersection Calculations for 2D and 3D

# Loop

Manages Loops for Multi Dimensional Vector Indexes.<br>
```cpp
LoopU3 loop(VectorU3(0, 0, 0), VectorU3(2, 4, 8));
for (VectorU3 u = loop.Min(); loop.Check(u).All(true); loop.Next(u))
{
	// loop
}
```

# _Show

Has ``operator<<`` for a lot of ValueTypes.<br>
Should this also have ``operator>>``?<br>
Rename to "_String"?<br>

