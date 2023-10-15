#!/usr/bin/python3
''' This module contains the Amenity class '''
from models.base_model import BaseModel


class Amenity(BaseModel):
    ''' Class representing Amenities '''
    name: str = ''
