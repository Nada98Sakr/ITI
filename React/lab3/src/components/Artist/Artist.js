import React from "react";
import './Artist.css'
import { Link } from "react-router-dom";

const Artist = (props) => {
    return (
        <div className="artistCard">
            <Link to={`/artists/${props.artist.id}`} className="link">
                <div className="artistImage">
                    <img src={props.artist.cover} alt="" />
                </div>
                <div className="artistData">
                    <p className="title">{props.artist.name}</p>
                </div>
            </Link>
        </div>
    );
}

export default Artist;