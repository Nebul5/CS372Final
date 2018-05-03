# CS372Final

Demonstrates the "Chain of Responsibility" design pattern by constructing a monster out of different body parts.

Each body part inherits from the base monster class, "bigMonster" and has its own way of handling certain typs of attacks individually.

"attackEvents" are either handled by the part of the monster that was attacked, or, if they aren't of a damage type that is handled by that part, they propagate up the chain to the next part of the monster that part is attached to.

This way an attack may sever a limb, blind the monster, break its arms, disable its claws, or just do damage depending on where it was hit and with what type of attack.
