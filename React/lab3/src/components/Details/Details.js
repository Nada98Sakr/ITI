import React, { useEffect, useState } from "react";
import { useParams } from "react-router";
import "./Details.css";
import Album from "../Album/Album";

const Details = () => {
    const API_URL = "http://localhost:3500/artists";

    const { id } = useParams();
    const [artist, setArtist] = useState(null);
    const [isLoading, setIsLoading] = useState(true);

    const getArtist = async () => {
        try {
            const response = await fetch(`${API_URL}/${id}`);
            const data = await response.json();
            setArtist(data);
            setIsLoading(false);
        } catch (error) {
            console.log("Error in getting artist details:", error);
            setIsLoading(false);
        }
    };

    useEffect(() => {
        getArtist();
    }, []);

    if (isLoading) {
        return <div>Loading...</div>;
    }

    if (!artist) {
        return null;
    }

    return (
        <div className="artistDetails">
            <div className="artistCover">
                <img className="artist" src={artist.cover} alt="Artist" />
                <p className="bio">{artist.bio}</p>
            </div>
            <p className="heading">Albums</p>
            <div className="artistAlbums">
                {artist.albums.map((album) => (
                    <Album album={album} key={album.albumId} />
                ))}
            </div>
        </div>
    );
};

export default Details;
