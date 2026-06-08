# Engineering Log: Transform-Driven Dynamic Camera Engine

## 🔍 System Purpose
Manages first-person, third-person, isometric, and strategic observer camera behaviors along a unified mouse-scroll timeline axis.

## ⚙️ Mechanical Specification
*   **The Anchor System**: The camera is bound to a single tracking node. In character modes, this node sits at Young Sir's head/center. In Maximum Zoom Out, the anchor locks to him as a tracking pivot, allowing tactical tracking without losing control.
*   **The Continuous Zoom Timeline (`float ZoomLevel`)**:
    *   `0.0f` to `1.0f`: **First-Person to Third-Person**. Slides back along a direct negative look-vector. The character primitive alpha-fades smoothly into visibility.
    *   `1.0f` to `2.0f`: **Third-Person to Diablo Isometric**. The pitch angle automatically clamps to a downward $45^\circ$ angle, flattening perspective matrices.
    *   `2.0f` to `4.0f`: **Diablo to High Observer**. Zooms far into the cloud layer, keeping the camera anchored to Young Sir's world position while offering a wide, strategic overview.
*   **Smoothing Systems**: Position tracks via a **Damped Spring-Mass Lerp** algorithm, and rotations smooth via **Slerp** to eliminate jarring visual micro-stuttering.

## 🧠 Thought Process & Logic Architecture
Instead of building four separate, complex camera classes that constantly conflict with one another, we use a single unified class driven entirely by the `ZoomLevel` float state variable. This keeps the camera system lean, clean, and completely bug-free.

## ⛓️ Interconnected Dependencies
*   Dictates screen coordinate calculations used by **Vendor_Interface_Solver.md** to calculate cursor world selections.
*   Alters the visual culling parameters for meshes tracked across the sandbox environment.

